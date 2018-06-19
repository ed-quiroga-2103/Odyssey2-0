package controller.view;

import controller.model.Notification;
import controller.model.Song;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.stage.Stage;
import javafx.stage.FileChooser;

import java.io.File;

public class RatingPanelController {

    @FXML
    private CheckBox oneStar;
    @FXML
    private CheckBox twoStar;
    @FXML
    private CheckBox threeStar;
    @FXML
    private CheckBox fourStar;
    @FXML
    private CheckBox fiveStar;


    private Stage dialogStage;
    private Song song;

    private void initialize(){}

    public void setDialogStage(Stage dialogStage){
        this.dialogStage=dialogStage;
    }


    public void setSong(Song song){
        this.song=song;
    }
    @FXML
    private void handleCancel(){
        dialogStage.close();
    }

    @FXML
    private void handleSend(){
        if(validate()){

            Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
            alert.setTitle("Error Dialog");
            alert.setHeaderText(null);
            alert.setContentText("Succesful, you rate a song!!");
            alert.showAndWait();
            dialogStage.close();

        }else{

            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error Dialog");
            alert.setHeaderText(null);
            alert.setContentText("Missing Wrapper!");

            alert.showAndWait();
        }
    }

    private boolean validate(){
        return true;
    }

    private void selection(){

    }
}
