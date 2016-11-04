//
//  HJPhotoKitManager.h
//  HJPhotoKit
//
//  Created by LZF on 16/11/1.
//  Copyright © 2016年 zf.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>
#import <AssetsLibrary/AssetsLibrary.h>

@class HJAssetModel;
@class HJAlbumModel;

@interface HJPhotoKitManager : NSObject
//时候修正图片转向
@property (nonatomic, assign) BOOL shouldFixOrientation;

/// 对照片排序，按修改时间升序，默认是YES。如果设置为NO,最新的照片会显示在最前面，内部的拍照按钮会排在第一个
@property (nonatomic, assign) BOOL sortAscendingByModificationDate;

+ (instancetype)manager;
//权限验证
- (BOOL)authorizationStatusAuthorized;

//获取相册
- (void)getCameraRollAlbum:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(HJAlbumModel *))completion;
- (void)getAllAlbums:(BOOL)allowPickingVideo allowPickingImage:(BOOL)allowPickingImage completion:(void (^)(NSArray<HJAlbumModel *> *))completion;
// 获取一组照片的总大小
- (void)getPhotosBytesWithArray:(NSArray <HJAssetModel *>*)photos completion:(void (^)(NSString *totalBytes))completion;

//获取图片
- (PHImageRequestID)getPhotoWithAsset:(id)asset photoWidth:(CGFloat)photoWidth completion:(void (^)(UIImage *, NSDictionary *, BOOL isDegraded))completion;

//获取原图
- (void)getOriginalPhotoDataWithAsset:(id)asset completion:(void (^)(NSData *data,NSDictionary *info))completion;
- (void)getOriginalPhotoWithAsset:(id)asset completion:(void (^)(UIImage *photo,NSDictionary *info))completion;

// 输出视频
- (void)getVideoOutputPathWithAsset:(id)asset completion:(void (^)(NSString *outputPath))completion;

//比较图片相似度
@end
