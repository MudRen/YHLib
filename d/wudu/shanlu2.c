inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
����һ����ɽ��С·����������ʯ���ɵ�̨�ף�ʪ�����ĳ�����
��̦������ȫ��ï�ܵ����֡�Զ������һ�������ɽ������
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "southup" : __DIR__"shanlu3",
                "northdown" : __DIR__"xiaolu",
        ]));

        setup();
        replace_program(ROOM);
}
