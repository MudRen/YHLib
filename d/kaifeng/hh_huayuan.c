inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�������ܶ��ڵĺ�԰��һ���ļ��������Ÿ�������Ļ�
�ݣ��������·����߲����޵Ĺ�ԡ���԰��һƬ���ţ�������
��һֻ�۷��������衣��һ��ʯ��С·ͨ��ǰ��һ��������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"hh_penquan",
  		"west" : __DIR__"hh_jiashan",
  		"north" : __DIR__"hh_road",
  		"south" : __DIR__"hh_hguangchang",
	]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
