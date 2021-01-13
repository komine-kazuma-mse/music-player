//以下、アノードコモンフルカラーLEDの定義
const int NUM_LED = 3;
const int LED_PIN[NUM_LED] = {9, 10, 11}; // LEDのピン番号
const int NUM_PATTERN = 4; //４種の発光パターン
const int PATTERN[NUM_PATTERN][NUM_LED] = {
  {LOW, HIGH, HIGH}, //緑色に点灯
  {HIGH, LOW, HIGH}, //青色に点灯
  {HIGH, HIGH, LOW}, //赤色に点灯
  {LOW, LOW, LOW}    //白色に点灯
};
//以下、ブザーの定義
const int OUTPUT_BUZZ = 3; //ブザーのピン番号の定義
int tone_length; //音の基準長さを指定
//以下、半固定抵抗の定義
const int INPUT_PIN_VOLUME = A0; //半固定抵抗のアナログピン番号の定義
int VOLUME; //半固定抵抗の抵抗値を0～1024までの範囲で示すための変数
//以下、Cdsセンサーの定義
int val = 0; //Cdsセンサーの値を格納するための変数
const int INPUT_PIN_CDS = A4;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_LED; ++ i) {
  pinMode(LED_PIN[i], OUTPUT); //各ピンを出力モードに設定
  }
  Serial.begin(9600); //シリアルモニタの設定
}

void loop() {
  // put your main code here, to run repeatedly:
  
  VOLUME = analogRead(INPUT_PIN_VOLUME); //抵抗値のアナログ値の読み取り
  val = analogRead(INPUT_PIN_CDS); //Cdsセンサのアナログ値の読み取り
  
  //曲のテンポの決定
  if(val < 100) {
    tone_length = 350; //暗いとき、音の基準長さを350に指定
    Serial.println("少し遅い");
  }else if(val < 500) {
    tone_length = 300; //音の基準長さを300に指定
    Serial.println("ふつう");
  }else {
    tone_length = 250; //明るいとき、音の基準長さを250に指定
    Serial.println("少し早い");
  }

  //曲の決定
  if (VOLUME < 256) {
    //曲名の表示
    Serial.println("１．ファミマの入店音");
    //緑色LEDを点灯
    for (int i = 0; i < NUM_LED; ++i) {
    digitalWrite(LED_PIN[i], PATTERN[0][i]); 
    } 
    //ファミマの入店音を鳴らす
    familymart();   
     
  }else if (VOLUME < 512){
    //曲名の表示
    Serial.println("２．スーパーマリオのテーマ");
    //青色LEDを点灯
    for (int i = 0; i < NUM_LED; ++i) {
    digitalWrite(LED_PIN[i], PATTERN[1][i]); 
    }
    //スーパーマリオのテーマを鳴らす
    mario();
    
  }else if (VOLUME < 768){
    //曲名の表示
    Serial.println("３．帝国のマーチ（ダースベイダーのテーマ）");
    //赤色LEDを点灯
    for (int i = 0; i < NUM_LED; ++i) {
    digitalWrite(LED_PIN[i], PATTERN[2][i]); 
    }
    //帝国のマーチを鳴らす
    imperial_march();
    
  }else {
    //曲名の表示
    Serial.println("４．彼こそが海賊（パイレーツオブカリビアンのテーマ）");
    //白色LEDを点灯
    for (int i = 0; i < NUM_LED; ++i) {
    digitalWrite(LED_PIN[i], PATTERN[3][i]); 
    }
    //パイレーツオブカリビアンのテーマを鳴らす
    pirates();
  }
}

//ファミマの入店音を鳴らす関数
void familymart() {
  tone(OUTPUT_BUZZ,740);
  delay(tone_length);
  tone(OUTPUT_BUZZ,587);
  delay(tone_length);
  tone(OUTPUT_BUZZ,440);
  delay(tone_length);
  tone(OUTPUT_BUZZ,587);
  delay(tone_length);
  tone(OUTPUT_BUZZ,659);
  delay(tone_length);
  tone(OUTPUT_BUZZ,880);
  delay(2*tone_length);
  tone(OUTPUT_BUZZ,440); 
  delay(tone_length); 
  tone(OUTPUT_BUZZ,659);
  delay(tone_length);
  tone(OUTPUT_BUZZ,740);
  delay(tone_length);
  tone(OUTPUT_BUZZ,659);
  delay(tone_length);
  tone(OUTPUT_BUZZ,440);
  delay(tone_length);
  tone(OUTPUT_BUZZ,587);
  delay(2*tone_length);
  noTone(OUTPUT_BUZZ);
  delay(tone_length);
}

//マリオのテーマを鳴らす関数
void mario() {
  tone(OUTPUT_BUZZ,660,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,660,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,660,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,510,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,660,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,770,tone_length/3);
  delay(5.5*tone_length/3);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(5.75*tone_length/3);

  tone(OUTPUT_BUZZ,510,tone_length/3);
  delay(4.5*tone_length/3);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(4*tone_length/3);
  tone(OUTPUT_BUZZ,320,tone_length/3);
  delay(5*tone_length/3);
  tone(OUTPUT_BUZZ,440,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,480,0.8*tone_length/3);
  delay(3.3*tone_length/3);
  tone(OUTPUT_BUZZ,450,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(2*tone_length/3);
  tone(OUTPUT_BUZZ,660,0.8*tone_length/3);
  delay(2*tone_length/3);
  tone(OUTPUT_BUZZ,760,0.5*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,860,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,700,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,760,0.5*tone_length/3);
  delay(3.5*tone_length/3);
  tone(OUTPUT_BUZZ,660,0.8*tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,520,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,580,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,480,0.8*tone_length/3);
  delay(5*tone_length/3);

  tone(OUTPUT_BUZZ,510,tone_length/3);
  delay(4.5*tone_length/3);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(4*tone_length/3);
  tone(OUTPUT_BUZZ,320,tone_length/3);
  delay(5*tone_length/3);
  tone(OUTPUT_BUZZ,440,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,480,0.8*tone_length/3);
  delay(3.3*tone_length/3);
  tone(OUTPUT_BUZZ,450,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(2*tone_length/3);
  tone(OUTPUT_BUZZ,660,0.8*tone_length/3);
  delay(2*tone_length/3);
  tone(OUTPUT_BUZZ,760,0.5*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,860,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,700,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,760,0.5*tone_length/3);
  delay(3.5*tone_length/3);
  tone(OUTPUT_BUZZ,660,0.8*tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,520,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,580,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,480,0.8*tone_length/3);
  delay(5*tone_length/3);

  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length);

  tone(OUTPUT_BUZZ,760,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,720,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,680,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,620,tone_length/2);
  delay(tone_length);

  tone(OUTPUT_BUZZ,650,tone_length/2);
  delay(tone_length);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length/2);

  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,570,tone_length/3);
  delay(2.2*tone_length/3);

  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length);

  tone(OUTPUT_BUZZ,760,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,720,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,680,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,620,tone_length/2);
  delay(tone_length);

  tone(OUTPUT_BUZZ,650,2*tone_length/3);
  delay(tone_length);

  tone(OUTPUT_BUZZ,1020,0.8*tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,1020,0.8*tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,1020,0.8*tone_length/3);
  delay(tone_length);

  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length);

  tone(OUTPUT_BUZZ,760,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,720,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,680,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,620,tone_length/2);
  delay(tone_length);

  tone(OUTPUT_BUZZ,650,tone_length/2);
  delay(tone_length);
  tone(OUTPUT_BUZZ,380,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length/2);

  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length);
  tone(OUTPUT_BUZZ,430,tone_length/3);
  delay(tone_length/2);
  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(tone_length/3);
  tone(OUTPUT_BUZZ,570,tone_length/3);
  delay(4.2*tone_length/3);

  tone(OUTPUT_BUZZ,585,tone_length/3);
  delay(4.5*tone_length/3);

  tone(OUTPUT_BUZZ,550,tone_length/3);
  delay(4.2*tone_length/3);

  tone(OUTPUT_BUZZ,500,tone_length/3);
  delay(3.6*tone_length/3);

  noTone(OUTPUT_BUZZ);
  delay(tone_length);
}

//帝国のマーチのリズムの関数
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(OUTPUT_BUZZ, note, duration);
  delay(duration);
 
  //Stop tone on buzzerPin
  noTone(OUTPUT_BUZZ);
  delay(tone_length/6);
}

//帝国のマーチを鳴らす関数
void imperial_march() {
  //first
  beep(440, 5*tone_length/3);
  beep(440, 5*tone_length/3);    
  beep(440, 5*tone_length/3);
  beep(349, 35*tone_length/30);
  beep(523, tone_length/2);  
  beep(440, 5*tone_length/3);
  beep(349, 35*tone_length/30);
  beep(523, tone_length/2);
  beep(440, 65*tone_length/30);
 
  delay(5*tone_length/3);
 
  beep(659, 5*tone_length/3);
  beep(659, 5*tone_length/3);
  beep(659, 5*tone_length/3);  
  beep(698, 35*tone_length/30);
  beep(523, tone_length/2);
  beep(415, 5*tone_length/3);
  beep(349, 35*tone_length/30);
  beep(523, tone_length/2);
  beep(440, 65*tone_length/30);
 
  delay(5*tone_length/3);

  //second
  beep(880, 5*tone_length/3);
  beep(440, tone_length);
  beep(440, tone_length/2);
  beep(880, 5*tone_length/3);
  beep(830, 32.5*tone_length/30);
  beep(784, 17.5*tone_length/30);
  beep(740, 12.5*tone_length/30);
  beep(698, 12.5*tone_length/30);    
  beep(740, 25*tone_length/30);
 
  delay(32.5*tone_length/30);
 
  beep(455, 25*tone_length/30);
  beep(622, 5*tone_length/3);
  beep(587, 32.5*tone_length/30);  
  beep(554, 17.5*tone_length/30);  
  beep(523, 12.5*tone_length/30);  
  beep(466, 12.5*tone_length/30);  
  beep(523, 25*tone_length/30);  
 
  delay(35*tone_length/30);

  //beep
  beep(349, 25*tone_length/30);  
  beep(415, 5*tone_length/3);  
  beep(349, 37.5*tone_length/30);  
  beep(523, 12.5*tone_length/30);
  beep(440, 5*tone_length/3);  
  beep(349, 37.5*tone_length/30);  
  beep(523, 12.5*tone_length/30);
  beep(440, 65*tone_length/30);  
 
  delay(65*tone_length/30);
}

//パイレーツオブカリビアンのテーマのリズムの関数
void beep2(int note, int duration)
{
  tone(OUTPUT_BUZZ, note, duration);          //tone(pin,frequency,duration)
  delay(duration);
}

//パイレーツオブカリビアンのテーマを鳴らす関数
void pirates() {
  //first
  beep2(330, 12.5*tone_length/30);
  beep2(392, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(440, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(523, 25*tone_length/30);
  beep2(523, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(523, 12.5*tone_length/30);
  beep2(587, 12.5*tone_length/30);
  beep2(494, 25*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(392, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  //second
  beep2(330, 12.5*tone_length/30);
  beep2(392, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(440, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(523, 25*tone_length/30);
  beep2(523, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(523, 12.5*tone_length/30);
  beep2(587, 12.5*tone_length/30);
  beep2(494, 25*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(392, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  //third
  beep2(330, 12.5*tone_length/30);
  beep2(392, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(440, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(523, 12.5*tone_length/30);
  beep2(587, 25*tone_length/30);
  beep2(587, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(587, 12.5*tone_length/30);
  beep2(659, 12.5*tone_length/30);
  beep2(698, 25*tone_length/30);
  beep2(698, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(659, 12.5*tone_length/30);
  beep2(587, 12.5*tone_length/30);
  beep2(659, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  //final
  beep2(440, 12.5*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(523, 25*tone_length/30);
  beep2(523, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(587, 25*tone_length/30);
  beep2(659, 12.5*tone_length/30);
  beep2(440, 25*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(440, 12.5*tone_length/30);
  beep2(523, 12.5*tone_length/30);
  beep2(494, 25*tone_length/30);
  beep2(494, 12.5*tone_length/30);
  beep2(0, 12.5*tone_length/30);

  beep2(523, 12.5*tone_length/30);
  beep2(440, 12.5*tone_length/30);
  beep2(494, 25*tone_length/30);
  beep2(0, 25*tone_length/30);
}
