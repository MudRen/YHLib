inherit ROOM;

void create()
{
      set("short", "�����ֶ���");
      set("long", @LONG
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã���ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"hcaeast2", 
          "west"  : __DIR__"hcaguangchang", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
