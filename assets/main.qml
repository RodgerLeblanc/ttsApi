/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.3

Page {
    ScrollView {
        Container {
            topPadding: ui.du(3)
            leftPadding: topPadding
            rightPadding: topPadding
            Container {
//                visible: false
                Label {
                    // Localized text with the dynamic translation and locale updates support
                    text: qsTr("Text to speak") + Retranslate.onLocaleOrLanguageChanged
                    textStyle.base: SystemDefaults.TextStyles.BigText
                }
                TextField {
                    id: message
                    hintText: "Enter your text to speak"
                    text: "Hello world!"
                }
                Label {
                    // Localized text with the dynamic translation and locale updates support
                    text: qsTr("Language") + Retranslate.onLocaleOrLanguageChanged
                    textStyle.base: SystemDefaults.TextStyles.BigText
                }
                TextField {
                    id: language
                    hintText: "Enter the 2 letters language of the message"
                    text: "en"
                }
                Label {
                    // Localized text with the dynamic translation and locale updates support
                    text: qsTr("Gender") + Retranslate.onLocaleOrLanguageChanged
                    textStyle.base: SystemDefaults.TextStyles.BigText
                }
                DropDown {
                    id: gender
                    Option {
                        text: "Male"
                        value: "ml"
                        selected: true
                    }
                    Option {
                        text: "Female"
                        value: "fm"
                    }
                }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    horizontalAlignment: HorizontalAlignment.Center
                    topPadding: ui.du(3)
                    CustomButton {
                        text: "TTS this with Google!"
                        onClicked: {
                            _ttsApi.google_tts(message.text, language.text.toLowerCase())
                        }
                    }
                    CustomButton {
                        leftPadding: ui.du(3)
                        text: "TTS this with Vozme!"
                        onClicked: {
                            _ttsApi.vozme_tts(message.text, gender.selectedOption.value, language.text.toLowerCase())
                        }
                    }
                }
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                topPadding: ui.du(5)
                CustomButton {
                    text: "Magic!"
                    onClicked: {
                        _magic.makeMagicHappen()
                    }
                }
            }
            Label {
                text: _magic.summary
                multiline: true
            }
        }
    }
}
