inherit ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
������һ����������Ĵ���ϣ���ʱ�����˹ҽ�����Ҵ�
����������ͨ���䵱��
LONG);
      set("outdoors", "wudang");
      set("exits", ([
          "southwest" : __DIR__"xiaolu1",
          "northeast" : "/d/wudang/sanbuguan",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
