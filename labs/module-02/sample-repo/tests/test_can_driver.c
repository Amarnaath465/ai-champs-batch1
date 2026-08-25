#include "can_driver.h"
#include "minitest.h"

static void test_bus_off_after_consecutive_failures(void)
{
    can_driver_t drv;
    can_driver_init(&drv);
    can_message_t msg = { .id = 0x100, .dlc = 8 };

    for (unsigned i = 0; i < CAN_BUS_OFF_THRESHOLD + 1; i++) {
        can_driver_send(&drv, &msg, true /* simulate_tx_failure */);
    }

    MT_ASSERT_EQ(can_driver_get_state(&drv), CAN_STATE_BUS_OFF,
                 "driver should enter BUS_OFF after exceeding the consecutive failure threshold");
}

static void test_recovery_after_bus_off(void)
{
    can_driver_t drv;
    can_driver_init(&drv);
    can_message_t msg = { .id = 0x100, .dlc = 8 };

    for (unsigned i = 0; i < CAN_BUS_OFF_THRESHOLD + 1; i++) {
        can_driver_send(&drv, &msg, true);
    }
    MT_ASSERT_EQ(can_driver_get_state(&drv), CAN_STATE_BUS_OFF,
                 "precondition failed: driver never reached BUS_OFF");

    for (uint32_t i = 0; i < CAN_BUS_OFF_RECOVERY_TICKS; i++) {
        can_driver_tick(&drv);
    }

    MT_ASSERT_EQ(can_driver_get_state(&drv), CAN_STATE_ERROR_ACTIVE,
                 "driver should recover to ERROR_ACTIVE after the recovery window elapses");
}

static void test_successful_send_clears_error_state(void)
{
    can_driver_t drv;
    can_driver_init(&drv);
    can_message_t msg = { .id = 0x200, .dlc = 4 };

    for (unsigned i = 0; i < CAN_BUS_OFF_THRESHOLD / 2 + 1; i++) {
        can_driver_send(&drv, &msg, true);
    }
    MT_ASSERT_EQ(can_driver_get_state(&drv), CAN_STATE_ERROR_PASSIVE,
                 "driver should be ERROR_PASSIVE after moderate consecutive failures");

    bool ok = can_driver_send(&drv, &msg, false /* success */);
    MT_ASSERT_TRUE(ok, "successful send should return true");
    MT_ASSERT_EQ(can_driver_get_state(&drv), CAN_STATE_ERROR_ACTIVE,
                 "a successful send should clear back to ERROR_ACTIVE");
}

int main(void)
{
    MT_RUN(test_bus_off_after_consecutive_failures);
    MT_RUN(test_recovery_after_bus_off);
    MT_RUN(test_successful_send_clears_error_state);
    return mt_summary();
}
