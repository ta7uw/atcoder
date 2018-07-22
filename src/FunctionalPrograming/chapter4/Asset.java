package FunctionalPrograming.chapter4;

public class Asset {
    public enum AssetType {BOND, STOCK}

    ;
    private final AssetType type;
    private final int value;

    public Asset(final AssetType assetType, final int assetValue) {
        type = assetType;
        value = assetValue;
    }

    public int getValue() {
        return value;
    }

    public AssetType getType() {
        return type;
    }
}

