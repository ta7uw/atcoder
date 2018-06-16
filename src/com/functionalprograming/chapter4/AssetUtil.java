package com.functionalprograming.chapter4;

import java.util.List;

public class AssetUtil {
    public static int totalAssetValues(final List<Asset> assets){
        return assets.stream()
                        .mapToInt(Asset::getValue)
                        .sum();
    }
}
