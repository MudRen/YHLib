inherit ROOM;

void create()
{
        set("short", "���ɽ·");
        set("long", @LONG
������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡�
�߸ߵ������������������У���Լ�ɼ����������ԵĽ���ͺ�
���˶���ϸ������Լ��Ľ��£�����̧ͷ��һ�ۣ�Ω��һ��С
��ˤ��ȥ������ǿ�˳û���٣������޲�����������ֻ����
��·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "northup" : __DIR__"tyroad6",
                "eastdown" : __DIR__"tyroad8",
        ]));
        set("no_clean_up", 0);
        setup();
}
