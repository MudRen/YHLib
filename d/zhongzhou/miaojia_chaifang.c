inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ�䰫С���߷���ƽʱ��Ϊ�ѷ��������á������ﲼ
�����������������ǻҳ����������Ѿ��ܾ�û���˴�ɨ�ˡ���
����һ��б���ż����ɲ�
LONG);
	set("exits", ([
  		"north" : __DIR__"miaojia_dayuan",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                "/d/wudu/obj/ganchai" : 2,
        ]));
	setup();
        replace_program(ROOM);
}
