
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ
�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ������Ⱥɽ���ƣ���춽�
�£��������������۵ף���ʱ���˺�����������������һƬ��
�ء������Ͼ�������ɽ���塣
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"kongdi",
                "northup"   : __DIR__"zhufeng",
        ]));

        setup();
        replace_program(ROOM);
}
