package controller.view;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import javafx.scene.image.ImageView;

public class mainContentController {

    @FXML
    private Label playList1;
    @FXML
    private Label PlayList2;
    @FXML
    private Label PlayList3;
    @FXML
    private ImageView img1;
    @FXML
    private ImageView img2;
    @FXML
    private ImageView img3;


    private MainApp mainApp;

    public void setMainApp(MainApp mainApp){
        this.mainApp=mainApp;
    }

    @FXML
    private void showAccount(){
        this.mainApp.initUserData();
    }

    @FXML
    private void showNotifications(){
        this.mainApp.initNotificationPanel();
    }



}
