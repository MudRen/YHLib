inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ��СС��ʯ�ݣ���ǰ�ݺ��߰������ز�ø�ͦ���ڵ�ʯ������
�����ģ����ղ���ʲô���⡣ʯ��������������һλ���ߣ���ʮ����
��ͣ�����������ϼ��ⶼ���˽�ȥ��ֱ��һ�����ã�˫Ŀȴ����
���������׸��١�ʯ�����ܵ�ǽ���Ϲ����˸�ʽ�������������κ�
һ�������ϰٻ�����ǧ�⾰��ȫ������֮�
LONG
        );
        set("exits", ([
            "out" : __DIR__"xiaoyuan",
        ]));

        set("objects", ([
                CLASS_D("meizhuang") + "/huang" : 1,
                __DIR__"obj/qin" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
