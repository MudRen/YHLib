inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����ѩɽ�µ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "north" : __DIR__"xsmidao2",
                "west"  : __DIR__"xsmidao4",
        ]));

	setup();
        replace_program(ROOM);
}
