import bb.cascades 1.3

Container {
    property alias text: myLabel.text
    signal clicked
    
    horizontalAlignment: HorizontalAlignment.Center
    verticalAlignment: VerticalAlignment.Center
    // DockLayout will put first item in the back and next item on top of it (instead of below it)
    layout: DockLayout {}
    
    ImageView {
        // We define the amd file as the image. amd file is the 9Slice property of the image to scale
        imageSource: "asset:///images/emptyButton.amd"
        verticalAlignment: VerticalAlignment.Fill
        horizontalAlignment: HorizontalAlignment.Fill
    }
    
    Container {
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
        // I add padding otherwise the text will get over the border of the circle
        leftPadding: ui.sdu(2) // 20
        rightPadding: leftPadding
        bottomPadding: leftPadding
        topPadding: leftPadding
        Label {
            id: myLabel
            multiline: true
        }
    }

    // This is how you listen for click event
    gestureHandlers: TapHandler {
        onTapped: {
            // emit clicked() signal
            clicked()
        }
    }
}
