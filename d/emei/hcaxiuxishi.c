inherit ROOM;

void create()
{
      set("short", "��Ϣ��");
      set("long", @LONG
�����Ƕ��һ����ֵ���Ϣ�ҡ�������������������������
���˺ܶ�ľ�����м���ҹ�����ֵ�Сʦ̫����˯������Ϣ����
����������
LONG);
      set("exits", ([
          "north" : __DIR__"hcachanfang", 
      ]));
      set("no_fight", 1);
      set("sleep_room", 1);
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
