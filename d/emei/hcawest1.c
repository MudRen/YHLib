inherit ROOM;

void create()
{
      set("short", "����������");
      set("long", @LONG
�����Ƕ��һ��������ȡ���������ͨ����������ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"hcawest2",
          "east"  : __DIR__"hcaguangchang", 
      ]));
      setup();
      replace_program(ROOM);
}
