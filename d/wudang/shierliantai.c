inherit ROOM;

void create()
{
        set("short", "ʮ����̨");
        set("long", @LONG
�������䵱������ʮ����̨��̨��̨֮����������������
�̾�������Զ����������ڡ�վ����̨��������������ǧҶ��
��֮�ϣ�ǧ�����ֶ��ڽ��¡������������߰�����Ļ�ɽ����
����ˮ�������塢��һ�������۵ס�
LONG);
        set("exits", ([
                "east" : __DIR__"jinding",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
