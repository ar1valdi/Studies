package org.example;
import static org.mockito.Mockito.*;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.Optional;

public class MageControllerTest {
    MageRepository repo;
    MageController controller;

    @Before
    public void setup() {
        repo = mock(MageRepository.class);
        controller = new MageController(repo);
    }

    @Test
    public void testFind() {
        Mage m = new Mage("Test", 10);

        when(repo.find("Test")).thenReturn(Optional.of(m));
        String resToProperAdd = controller.find("Test");

        when(repo.find("Test")).thenReturn(Optional.empty());
        String resToInvalidAdd = controller.find("Test");

        Assert.assertEquals(m.toString(), resToProperAdd);
        Assert.assertEquals("not found", resToInvalidAdd);
    }

    @Test
    public void testDelete() {
        doNothing().when(repo).delete("Test");
        String resToProperAdd = controller.delete("Test");

        doThrow(IllegalArgumentException.class).when(repo).delete("Test");
        String resToInvalidAdd = controller.delete("Test");

        Assert.assertEquals("done", resToProperAdd);
        Assert.assertEquals("not found", resToInvalidAdd);
    }

    @Test
    public void testAdd() {
        Mage m = new Mage("Test", 10);

        doNothing().when(repo).save(m);
        String resToProperAdd = controller.save("Test", "10");

        doThrow(IllegalArgumentException.class).when(repo).save(m);
        String resToInvalidAdd = controller.save("Test", "10");

        Assert.assertEquals("done", resToProperAdd);
        Assert.assertEquals("bad request", resToInvalidAdd);
    }
}
