//
//  saveFile.swift
//  Fiftygram
//
//  Created by Ivan Naranjo on 23.05.20.
//  Copyright © 2020 CS50. All rights reserved.
//

import UIKit

class ImageSaver: NSObject {
    
    func writePhotoToAlbum(image: UIImage) {
        UIImageWriteToSavedPhotosAlbum(image, self, nil, nil)
    }
    
}
