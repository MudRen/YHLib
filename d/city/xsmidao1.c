inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����ѩɽ�µ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "east" : __DIR__"xsmidao",
                "west" : __DIR__"xsmidao2",
        ]));

	setup();
        replace_program(ROOM);
}
