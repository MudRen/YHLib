inherit ROOM;

void create()
{
      set("short", "�����޹�");
      set("long", @LONG
���Ƕ���ɽ�𶥻��������һƬС���ֶ����޹���
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhou" : 1,
      ]));
      set("exits", ([
          "south" : __DIR__"xiaoshulin4", 
      ]));
      setup();
      replace_program(ROOM);
}
