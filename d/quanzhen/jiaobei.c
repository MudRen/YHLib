inherit ROOM;

void create()
{
        set("short", "�̱�");
        set("long", @LONG
������ȫ��̵Ḻ̌����ڵأ�·������һ��󱮡�������
�߾������������ĵ�����������--ȫ��̵Ĵ����ˡ���������
ʯ�ף���֪��ͨ�������������ɽ��·��
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("objects",([
                CLASS_D("quanzhen") + "/zhao" : 1,
                CLASS_D("quanzhen") + "/zhou" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
