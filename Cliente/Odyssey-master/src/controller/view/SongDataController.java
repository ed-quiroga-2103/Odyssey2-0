package controller.view;

import controller.model.Base64Converter;
import controller.model.Song;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import controller.MainApp;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.scene.paint.Color;
import javafx.stage.FileChooser;
import javafx.scene.shape.Rectangle;

import java.io.ByteArrayInputStream;
import java.io.File;

import java.io.FileOutputStream;
import java.io.IOException;


public class SongDataController {

    private MainApp mainApp;
    private Song currentSong;
    private MediaPlayer player;
    Base64Converter converter=new Base64Converter();
    @FXML
    private MediaView media;
    @FXML
    private ImageView image;
    @FXML
    private Label name;
    @FXML
    private Label artist;
    @FXML
    private Label album;
    @FXML
    private Label rate;
    @FXML
    final HBox hbox = new HBox(2);

    public void setMainApp(MainApp mainApp) {
        this.mainApp = mainApp;
    }
    public void setCurrentSong(Song currentSong){
        this.currentSong=currentSong;
    }

    private void setSongData(){
        this.name.setText(this.currentSong.getSongName());
        this.album.setText(this.currentSong.getSongAlbum());
        this.artist.setText(this.currentSong.getSongArtist());
        this.updateImage();

    }

    private void updateImage(){
        if(currentSong.getImage64()!=null) {
            byte[] bytes = mainApp.converter.decode64(currentSong.getImage64());
            this.image.setImage(new javafx.scene.image.Image(new ByteArrayInputStream(bytes)));
        }
    }

    @FXML
    private void loadPhoto(){
        FileChooser chooser=new FileChooser();
        FileChooser.ExtensionFilter extFilters=new FileChooser.ExtensionFilter("png files(*.png)","*.png");
        chooser.getExtensionFilters().add(extFilters);

        File file = chooser.showOpenDialog(mainApp.getPrimaryStage());
        currentSong.setImage64(mainApp.converter.encode64(file));
        this.updateImage();

    }

    @FXML
    private void playSong() {
        byte[] byteArray = converter.decode64(currentSong.getSongfile64());

        try {

            File tempFile = File.createTempFile("currentSong", ".mp4", null);
            FileOutputStream fos = new FileOutputStream(tempFile);
            fos.write(byteArray);
            Media media = new Media(tempFile.toURI().toString());
            MediaPlayer player = new MediaPlayer(media);



            this.media.setMediaPlayer(player);
            this.media.setSmooth(true);


            player.play();


        }catch (IOException e){
            e.printStackTrace();
        }
    }

    @FXML
    private void pauseSong(){

        this.player.pause();
    }

    @FXML
    private void test(){
        FileChooser chooser=new FileChooser();
        FileChooser.ExtensionFilter extFilters=new FileChooser.ExtensionFilter("mp4 files(*.mp4)","*.mp4");
        chooser.getExtensionFilters().add(extFilters);

        File file = chooser.showOpenDialog(mainApp.getPrimaryStage());
        currentSong.setSongfile64(converter.encode64(file));

    }

    @FXML
    private void rateSong(){
        int votes=currentSong.getVotes()+1;
        currentSong.setVotes(votes);

    }
}
