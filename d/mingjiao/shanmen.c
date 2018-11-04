// Room: /d/mingjiao/shanmen.c
// Date: Java 97/04/3

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����ɽ��");
    set("long", @LONG
һ���޴����Ȼʯ�ź������Ƭɽ��֮�䣬ʯ�����Ϸ�����
��������������֣������̡����ּ���Щ���䣬����ȥ�����Զ��
��λ��ʮ����Ĵ��ֳָֽ�����ɽ�����ࡣ
LONG );
    set("exits", ([
        "westup" : __DIR__"shanlu1",
        "east" : __DIR__"tomen1",
    ]));
    set("outdoors", "mingjiao");
    set("objects",([
        __DIR__"npc/jieyinshi" : 1,
        "/kungfu/class/mingjiao/lengqian" : 1,
    ]));

    setup();
}

int valid_leave(object me, string dir)
{
    object *inv;
    int i;
    if ((me->query("family/family_name") != "����" ||
         me->query("family/family_name") != "�䵱��" ) &&
         dir == "westup")
    {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") &&                ((string)inv[i]->query("equipped")=="wielded"))
                 if(objectp(present("leng qian", environment(me))))
                     return notify_fail("��ǫ��ס��˵������λ" +
                         RANK_D->query_respect(me) + "����±��С��ҽ̹̽���"
			 "������Ͳ�\n�óֱ�����ɽ������¡�\n");
    }
    return ::valid_leave(me, dir);
}

