
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ
�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ������Ⱥɽ���ƣ���춽�
�£��������������۵ף���ʱ���˺�����������������һ��ɽ
·�������Ͼ�������ɽ���塣
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shanlu3",
                "eastup"    : __DIR__"zhufeng",
        ]));

        setup();
        replace_program(ROOM);
}
