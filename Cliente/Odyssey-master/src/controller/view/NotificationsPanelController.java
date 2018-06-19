package controller.view;

import controller.model.Notification;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;

public class NotificationsPanelController {

    @FXML
    private Label from;
    @FXML
    private TextArea message;

    private Stage dialogStage;
    private Notification notification;

    private void initialize(){}

    public void setDialogStage(Stage dialogStage){
        this.dialogStage=dialogStage;
    }

    public void setNotification(Notification notification){
        this.notification=notification;

        this.from.setText(notification.getFrom());
        this.message.setText(notification.getMessage());
    }

    @FXML
    private void handleClose(){
        dialogStage.close();
    }

}
