#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ݵĹ���Ͳ��㣬������Ƣ��ɽ����Ĳ�ũ����м���
�����ӱ��������������˵�ɧ�Һ͹ٸ��Ŀ�����˰��ÿ�꿪��
�ɲ輾�ڣ���Ҫ�����ϺõĲ�Ҷ�����Ҷ����Ů���������ճ�
���ժ�����ڻ��������±��ƣ�����ؾ������㴦�����㣬��
��Ů���㣬��˵�������ᾫ����ʮ�����
LONG);
        set("exits", ([
                "north" : __DIR__"donglang2",
        ]));
        set("objects",([
                __DIR__"npc/xiaocui" : 1,
                __DIR__"obj/mitao" : 3,
                __DIR__"obj/dawancha" : 4,
        ]));
        setup();
}
