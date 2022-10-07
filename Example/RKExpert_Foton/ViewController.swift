//
//  ViewController.swift
//  RKExpert_Foton
//
//  Created by 刘爽 on 09/29/2022.
//  Copyright (c) 2022 刘爽. All rights reserved.
//

import UIKit
//import RokidRASDK

class ViewController: UIViewController {
    @IBOutlet weak var textField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        textField.text = UserDefaults.standard.value(forKey: "AccountSaveKey") as? String
    }

    @IBAction func loginAction(_ sender: Any) {
        guard textField.text?.count ?? 0 > 0 else {
            return
        }
        UserDefaults.standard.setValue(textField.text!, forKeyPath: "AccountSaveKey")
        UserDefaults.standard.synchronize()
//        if RokidRASDKManager.shared().loginSuccess() {
//            RokidRASDKManager.shared().enterClosedLoopList()
//            return
//        }
//        RokidRASDKManager.shared().initWithUserName(textField.text!, with: .FTFormHomeIndex, withData: [:]) {
//            print("登录成功！！！")
//        } onFailed: { errCode, errMsg in
//            print("登录失败 Msg:\(errMsg)")
//        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

