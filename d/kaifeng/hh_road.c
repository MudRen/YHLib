inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ���̵�ʮ��ƽ����ʯ��·��·�����Ǳ���ɨ�ĸɸ�
�����������ȥ�Ǹ���Բ�����������㣬�������ͨ���ܶ�
�Ĵ�������������һ��С����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"northup" : __DIR__"hh_xiaozhu",
  		"south" : __DIR__"hh_huayuan",
	]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
