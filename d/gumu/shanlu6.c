
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ
�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ������Ⱥɽ���ƣ���춽�
�£��������������۵ף���ʱ���˺��������������ºͱ��ϸ�
��һ��ɽ·���������ǰ���̶��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup"    : __DIR__"shanlu5",
                "eastdown"   : __DIR__"shanlu7",
                "southdown"  : __DIR__"baimatan",
        ]));

        setup();
        replace_program(ROOM);
}
