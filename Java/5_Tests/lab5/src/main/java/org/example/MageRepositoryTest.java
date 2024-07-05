package org.example;

import org.junit.Assert;
import org.junit.Test;

public class MageRepositoryTest {

    @Test
    public void testFind() {
        MageRepository mr = new MageRepository();

        Mage m1 = new Mage("Test_1", 100);
        Mage m2 = new Mage("Test_2", 100);
        mr.save(m1);
        mr.save(m2);

        Mage found_1 = mr.find("Test_1").orElse(null);
        Mage found_2 = mr.find("Test_2").orElse(null);
        Mage found_3 = mr.find("Test_3").orElse(null);

        Assert.assertEquals(m1, found_1);
        Assert.assertEquals(m2, found_2);
        Assert.assertNull(found_3);
    }

    @Test
    public void testDelete() {
        MageRepository mr = new MageRepository();

        mr.save(new Mage("Test_1", 100));
        mr.save(new Mage("Test_2", 100));

        boolean deleted_good_1 = returnBoolTrueIfDeleted(mr, "Test_1");
        boolean deleted_bad_not_empty = returnBoolTrueIfDeleted(mr, "Test_1");
        boolean deleted_good_2 = returnBoolTrueIfDeleted(mr, "Test_2");
        boolean deleted_bad_empty = returnBoolTrueIfDeleted(mr, "Test_2");

        Assert.assertTrue(deleted_good_1);
        Assert.assertTrue(deleted_good_2);
        Assert.assertFalse(deleted_bad_not_empty);
        Assert.assertFalse(deleted_bad_empty);
    }

    @Test
    public void testAdd() {
        MageRepository mr = new MageRepository();

        Mage m1_1 = new Mage("Test_1", 100);
        Mage m1_2 = new Mage("Test_1", 100);
        Mage m1_3 = new Mage("Test_1", -100);
        Mage m2_1 = new Mage("Test_2", 123);
        Mage m3_1 = new Mage("Test_3", 123);

        boolean added_1_1 = returnBoolTrueIfAdded(mr, m1_1);
        boolean added_1_2 = returnBoolTrueIfAdded(mr, m1_2);
        boolean added_1_3 = returnBoolTrueIfAdded(mr, m1_3);
        boolean added_2_1 = returnBoolTrueIfAdded(mr, m2_1);
        boolean added_3_1 = returnBoolTrueIfAdded(mr, m3_1);

        Assert.assertTrue(added_1_1);
        Assert.assertFalse(added_1_2);
        Assert.assertFalse(added_1_3);
        Assert.assertTrue(added_2_1);
        Assert.assertTrue(added_3_1);
    }

    private boolean returnBoolTrueIfAdded(MageRepository mr, Mage m) {
        try {
            mr.save(m);
            return true;
        } catch (IllegalArgumentException ex) {
            return false;
        }
    }

    private boolean returnBoolTrueIfDeleted(MageRepository mr, String name) {
        try {
            mr.delete(name);
            return true;
        } catch (IllegalArgumentException ex) {
            return false;
        }
    }
}
