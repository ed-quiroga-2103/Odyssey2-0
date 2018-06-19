package controller.view;

import controller.MainApp;
import controller.model.User;
import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.scene.control.Spinner;
import javafx.scene.control.TextField;
import org.json.simple.JSONObject;

/*import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;
import javax.activation.*;*/

import java.io.IOException;
import java.io.StringWriter;

public class SignUpController {


    //*******************************Class fields******************************//


    @FXML
    private TextField userName;
    @FXML
    private TextField fullName;
    @FXML
    private PasswordField userPassword;
    @FXML
    private Spinner<Integer> userAge;

    private MainApp mainApp;


    //*******************************Class Methods******************************//


    public void setMainApp(MainApp mainApp){
        this.mainApp=mainApp;
    }

    @FXML
    private  void handleRegister(){

        /*if(validate()) {

            //create a new user with input Wrapper

            User tempUser = new User();
            tempUser.setUserName(userName.getText());
            tempUser.setFullName(fullName.getText());
            tempUser.setAge(userAge.getValue());
            tempUser.setPassword(userPassword.getText());

            //send the new user to the main list

            //mainApp.getFriendList().add(tempUser);


            //send Wrapper to server

            JSONObject tempJson=mainApp.sendRequest(0,newJson());
            if(tempJson.get("confirmation").equals(true)) {
                //show confirmation dialog
                mainApp.showInfoDialog("Congratulations, new you are part of Odyssey!\n        " +
                        "Odyssey changing life with music");
            }else{
                mainApp.showErrorDialog("Failed connection with server");
            }




            //set next scene

            mainApp.initSignIn();

        }else{

            mainApp.showErrorDialog("Missing information!!");
        }
    }

    private boolean validate(){

        if(userName.getText().equals("")){

            return false;
        }
        if(fullName.getText().equals("")){

            return false;
        }
        if(userPassword.getText().equals("")){

            return false;
        }

        return true;
    }


    private String newJson(){
        try {
            JSONObject tempJson = new JSONObject();
            tempJson.put("username", userName.getText());
            tempJson.put("pass", userPassword.getText());
            tempJson.put("name", fullName.getText());
            tempJson.put("age", userAge.getValue().toString());
            tempJson.put("genres", "");

            StringWriter out = new StringWriter();
            tempJson.writeJSONString(out);
            String jsonText = out.toString();
            return jsonText;

        }catch (IOException e){
            e.printStackTrace();
            return null;
        }*/




    }

    @FXML
    private void handleCancel(){
        mainApp.initSignIn();
    }

}
