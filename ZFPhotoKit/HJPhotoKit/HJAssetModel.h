//
//  HJAssetModel.h
//  HJPhotoKit
//
//  Created by LZF on 16/11/1.
//  Copyright © 2016年 zf.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,HJAssetMediaType) {
    HJAssetModelMediaTypePhoto = 0,
    HJAssetModelMediaTypeLivePhoto,
    HJAssetModelMediaTypeVideo,
    HJAssetModelMediaTypeAudio

};

@interface HJAssetModel : NSObject
@property (nonatomic, strong) id asset;             // < PHAsset or ALAsset
@property (nonatomic, assign) BOOL isSelected;      // < The select status of a photo, default is No
@property (nonatomic, assign) HJAssetMediaType type;

@end

@interface HJAlbumModel : NSObject
@property (nonatomic, strong) NSString *name;        ///< The album name
@property (nonatomic, assign) NSInteger count;       ///< Count of photos the album contain
@property (nonatomic, strong) id result;             ///< PHFetchResult<PHAsset> or ALAssetsGroup<ALAsset>

@end
