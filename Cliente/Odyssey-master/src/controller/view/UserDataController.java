package controller.view;

import controller.model.User;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.FileChooser;


import javax.imageio.ImageIO;
import javax.sound.sampled.AudioInputStream;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;

public class UserDataController {


    private MainApp mainApp;
    @FXML
    private Label name;
    @FXML
    private Label userName;
    @FXML
    private Label email;
    @FXML
    private Label age;
    @FXML
    private ImageView image;
    @FXML
    private PasswordField oldPassword;
    @FXML
    private PasswordField newPassword;


    public void setMainApp(MainApp mainApp){
        this.mainApp=mainApp;
    }

    public void setUser(){
        setUserData();
    }

    private void setUserData(){

        this.name.setText(this.mainApp.getCurrentUser().getFullName());
        this.userName.setText(this.mainApp.getCurrentUser().getUserName());
        this.email.setText(this.mainApp.getCurrentUser().getEmail());
        this.age.setText(Integer.toString(this.mainApp.getCurrentUser().getAge()));
    }

    private void updatePhoto(){

        byte[] bytes=mainApp.converter.decode64(mainApp.getCurrentUser().getImage64());
        this.image.setImage(new javafx.scene.image.Image(new ByteArrayInputStream(bytes)));
    }

    @FXML
    private void getBack(){
        this.mainApp.initMainContent();
    }

    @FXML
    private void loadPhoto(){
        FileChooser chooser=new FileChooser();
        FileChooser.ExtensionFilter extFilters=new FileChooser.ExtensionFilter("png files(*.png)","*.png");
        chooser.getExtensionFilters().add(extFilters);

        File file = chooser.showOpenDialog(mainApp.getPrimaryStage());
        mainApp.getCurrentUser().setImage64(mainApp.converter.encode64(file));
        this.updatePhoto();

    }

    @FXML
    private void changePassword(){

        if(oldPassword.getText().equals(mainApp.getCurrentUser().getPassword())){
            mainApp.getCurrentUser().setPassword(this.newPassword.getText());
            System.out.print(mainApp.getCurrentUser().getPassword());
        }else{
            mainApp.showErrorDialog("Incorrect Password");
        }

    }

}
