inherit ROOM;

void create()
{
      set("short", "�����ֶ���");
      set("long", @LONG
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã���ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"hcazhaitang", 
          "north" : __DIR__"hcaeast1", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
