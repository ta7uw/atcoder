package FunctionalPrograming.chapter4;

import org.junit.Assert;
import org.junit.Test;
import java.util.Arrays;
import java.util.List;


public class AssetUtilTest {
    @Test
    public void totalAssetValuesTest() {
        final List<Asset> assets = Arrays.asList(
                new Asset(Asset.AssetType.BOND, 1000),
                new Asset(Asset.AssetType.BOND, 2000),
                new Asset(Asset.AssetType.STOCK, 3000),
                new Asset(Asset.AssetType.STOCK, 4000)
        );
        Assert.assertEquals(10000, AssetUtil.totalAssetValues(assets, asset -> true));
        Assert.assertEquals(3000, AssetUtil.totalAssetValues(assets,
                asset -> asset.getType() == Asset.AssetType.BOND));
        Assert.assertEquals(7000, AssetUtil.totalAssetValues(assets,
                asset -> asset.getType() == Asset.AssetType.STOCK));
     }

}
