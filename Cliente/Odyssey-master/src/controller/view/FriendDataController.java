package controller.view;

import controller.model.Notification;
import controller.model.User;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import javafx.scene.image.ImageView;

import java.io.ByteArrayInputStream;

public class FriendDataController {

    private MainApp mainApp;
    private User currentFriend;
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
    private TextArea message;


    public void setMainApp(MainApp mainApp){
        this.mainApp=mainApp;
    }

    public void setUser(User user){
        this.currentFriend=user;
        this.name.setText(user.getFullName());
        this.userName.setText(user.getUserName());
        this.email.setText(user.getEmail());
        this.age.setText(Integer.toString(user.getAge()));
        if(user.getImage64()!=null) {
            byte[] bytes = mainApp.converter.decode64(user.getImage64());
            this.image.setImage(new javafx.scene.image.Image(new ByteArrayInputStream(bytes)));
        }
    }

    @FXML
    private  void sendNotification(){
        //Notification tempNotification=new Notification();
    }

    @FXML
    private void deleteFriend(){

        //send dat to server
        //return the new list of friends
        //update list
    }

    @FXML
    private void sendMessage(){
        /*Notification tempNotification=new Notification();
        tempNotification.setMessage(this.message.getText());*/
    }
}
