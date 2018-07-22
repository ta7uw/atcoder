package FunctionalPrograming.chapter4;

import org.jboss.arquillian.container.test.api.Deployment;
import org.jboss.arquillian.junit.Arquillian;
import org.jboss.shrinkwrap.api.ShrinkWrap;
import org.jboss.shrinkwrap.api.asset.EmptyAsset;
import org.jboss.shrinkwrap.api.spec.JavaArchive;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;

import java.math.BigDecimal;


@RunWith(Arquillian.class)
public class CalculateNAVTest {
    @Deployment
    public static JavaArchive createDeployment() {
        return ShrinkWrap.create(JavaArchive.class)
                .addClass(CalculateNAV.class)
                .addAsManifestResource(EmptyAsset.INSTANCE, "beans.xml");
    }

    @Test
    public void computeStockWorth() {
        final CalculateNAV calculateNav = new CalculateNAV(ticker->new BigDecimal("6.01"));
        BigDecimal expected = new BigDecimal("6010.00");
        Assert.assertEquals(0,
                calculateNav.computeStockWorth("GOOG", 1000).compareTo(expected),
                0.001);

    }
}
