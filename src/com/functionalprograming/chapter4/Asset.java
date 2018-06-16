package com.functionalprograming.chapter4;

public class Asset {
    public enum AssetType {BOND, STOCK}

    ;
    private final AssetType type;
    private final int value;

    public Asset(final AssetType assetType, final int assetvalue) {
        type = assetType;
        value = assetvalue;
    }

    public int getValue() {
        return value;
    }

    public AssetType getType() {
        return type;
    }
}

