inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����Ѫ���ŵ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "up"    : "/d/xuedao/sroad8",
                "north" : __DIR__"xdmidao2",
        ]));

	setup();
        replace_program(ROOM);
}
