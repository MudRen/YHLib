inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
����Ѫ���ŵ�ɮ��Ϊ�˷���������ԭ���ص������˵��ܵ�
�Ա���֪��������������
LONG);

        set("exits", ([
                "up"   : __DIR__"datiepu",
                "west" : __DIR__"xdmidao3",
        ]));

	setup();
        replace_program(ROOM);
}
