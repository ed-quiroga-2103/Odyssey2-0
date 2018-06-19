package controller.view;

import controller.MainApp;
import controller.model.Song;
import controller.model.User;
import controller.model.xmlManager;
import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;



public class SignInController {

    //*******************************Class fields******************************//

    private MainApp mainApp;
    private User mainUser=new User(); //Current user

    @FXML
    private TextField userName;
    @FXML
    private PasswordField userPassword;


    //*******************************Class Methods******************************//

    public void setMainApp(MainApp mainApp) {
        this.mainApp = mainApp;
    }

    private boolean validate() {

        //mainApp.setCurrentUser(new User("karolyi15","Gunther Karolyi",20,"","karolyi15@hotmail.com"));
        //System.out.print(mainApp.client.sendData("holaaaa"));
        User user=new User();
        user.setPassword("user");
        user.setUserName("user");
        user.setFullName("user");
        String data[]=mainApp.xmlManager.xmlReader(mainApp.client.sendData(mainApp.xmlManager.xmlWritter(1,user,null)));
        mainApp.setCurrentUser(new User(data[0],data[1],0,data[0],data[0]));
        return true;
    }

    @FXML
    private void handleEnter() {

        if (validate()) {
            mainApp.initContent();
        } else {
            mainApp.showErrorDialog("You are not a user, please sign up first!");
        }
    }

    @FXML
    private void handleSignUp() {

        mainApp.initSignUp();

    }


}

