
inherit ROOM;

void create()
{
        set("short", "��У��");
        set("long", @LONG
����һ��λ�����ɽɽ����Բƺ������Ⱥɽ������ɽ����
��һ��ء�ÿ�����£�ȫ���ɱ�춴˵ؾ��д�У���Կ�������
��������һ���Ľ�����������һ����᫵�ɽ����������һ��
ͨ���嶥��ɽ·�������б�����������ֻ��Զ��ʮ�Ŵ�������
�����������ɢ��ɽ�䡣
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup"     : "/d/quanzhen/shijie1",
                "westup"      : __DIR__"shanlu7",
                "southdown"   : __DIR__"shanlu8",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/pi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
