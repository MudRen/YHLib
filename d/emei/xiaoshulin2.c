inherit ROOM;

void create()
{
      set("short", "С����");
      set("long", @LONG
���Ƕ���ɽ�𶥻��������һƬС���֡�����û��·����
������ϡ��Щ�㼣���ƺ��������߹���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south"   : __DIR__"xiaoshulin3", 
          "north"   : __DIR__"xiaoshulin1", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
