package controller.view;

import controller.model.Notification;
import controller.model.Song;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.stage.FileChooser;
import org.json.simple.JSONObject;
import controller.model.Base64Converter;
import java.io.File;
import java.io.IOException;
import java.io.StringWriter;

public class AddSongController {

    @FXML
    private TextField songName;
    @FXML
    private TextField songArtist;
    @FXML
    private TextField songAlbum;
    @FXML
    private TextArea songLyrics;

    private Song song;
    private Stage dialogStage;
    private Base64Converter converter=new Base64Converter();

    private void initialize(){}

    public void setDialogStage(Stage dialogStage){
        this.dialogStage=dialogStage;
    }

    public void setSong(Song song){
        this.song=song;

        this.songName.setText(song.getSongName());
        this.songAlbum.setText(song.getSongAlbum());
        this.songArtist.setText(song.getSongArtist());
        this.songLyrics.setText(song.getSongLyrics());
    }


    @FXML
    private void handleCancel(){
        dialogStage.close();
    }


    @FXML
    private void handleDone(){

        if(validate()){

            this.song.setSongName(songName.getText());
            this.song.setSongAlbum(songAlbum.getText());
            this.song.setSongArtist(songArtist.getText());
            this.song.setSongLyrics(songLyrics.getText());


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

        if(songName.getText().equals("")){
            return false;
        }
        if(songArtist.getText().equals("")){
            return false;
        }
        if(songAlbum.getText().equals("")){
            return false;
        }

        return true;

    }

    @FXML
    private void handleOpenMusicFile(){
        try {
            FileChooser chooser = new FileChooser();

            FileChooser.ExtensionFilter extFilters = new FileChooser.ExtensionFilter("mp3 files(*.mp3)", "*.mp3");
            chooser.getExtensionFilters().add(extFilters);

            File file = chooser.showOpenDialog(dialogStage);
            this.song.setSongfile64(converter.encode64(file));

        }catch (Exception e){
            e.printStackTrace();
        }

    }

}
