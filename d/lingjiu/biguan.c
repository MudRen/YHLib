inherit ROOM;
void create()
{
  	set("short", "�չ���");
  	set("long", @LONG
���ﵱ�걾����ɽͯ�ѱչ������ĵط�������ɽͯ����ȥ
֮�������ӱ㽫�˴�Ų������÷������Ľ��þ�ס��
LONG );
  	set("sleep_room", 1);
  	set("exits",([
      		"south" : __DIR__"men3",
  	]));
        set("objects",([
                CLASS_D("lingjiu") + "/jujian" : 1,
        ]));

  	setup();
  	replace_program(ROOM);
}
