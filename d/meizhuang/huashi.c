// huashi.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǵ������Ļ��ң��׻�˵���黭���ּң����Ե��������鷨
Ҳ���൱�Ĺ�������Ȼ����������ͺ���̺ܶ࣬���������Ľ�������
�����鷨���У�Ҳ��ν�����������ˡ�����ĳ�������Ҳ�࣬Ψ
һ��ͬ���������ǽ�ϲ�û�йҵ������ĵ�����ʣ����ǹ������ǰ
�����ҵ����������ڵ������Լ�����һ��д�š������С������á�
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang1",
        ]));

        set("objects", ([
                CLASS_D("meizhuang") + "/danqing" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}