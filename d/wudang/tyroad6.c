inherit ROOM;

void create()
{
        set("short", "���ɽ·");
        set("long", @LONG
������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡�
�߸ߵ������������������У���Լ�ɼ����������ԵĽ���ͺ�
���˶���ϸ������Լ��Ľ��£�����̧ͷ��һ�ۣ�Ω��һ��С
��ˤ��ȥ������ǿ�˳û���٣������޲�����������
LONG );
        set("outdoors", "wudang");
        set("exits", ([
                "westup" : __DIR__"tyroad5",
                "southdown" : __DIR__"tyroad7",
        ]));
        setup();
}
