inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ컨���ܶ��ڵĺ����������൱�Ŀ�����������
��ǽ���������˸������˵��漣��ֻ��һ���������ã������
�֣������縻���̼�һ�㣬Ц�ݺͰ������Ǵ��顣�Ա�վ�ż�
���컨��Ļ��ڣ���ǰ����һ���컨���������ࡣ
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_zoulang6",
  		"east" : __DIR__"hh_zoulang7",
  		"north" : __DIR__"hh_zoulang8",
  		"south" : __DIR__"hh_zhengting",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/zhao" : 1,
                __DIR__"npc/honghua2" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
