
inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
�����ߵ�������ɽ��ɽ����ǰ�����ȫ��̵��ܲ�������
�ˡ�������ɽ�������ߵʹ������¡�������Χ��ľɭɭ������
���֣���ɫ���ġ�ǰ����ǽ���ߣ��������ݣ�����һ��������
�ߵ����ɼľ��ͭ����(door)���Ϸ�һ����ң����ɷ������
�š����������������֡������ǹ㳡��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown"   : __DIR__"daxiaochang",
        ]));

        setup();
        replace_program(ROOM);
}
