
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ
�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ������Ⱥɽ���ƣ���춽�
�£��������������۵ף���ʱ���˺��������������º����ϸ�
��һ��ɽ·��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "westup"     : __DIR__"shanlu4",
                "southdown"  : __DIR__"shanlu6",
        ]));

        setup();
        replace_program(ROOM);
}
