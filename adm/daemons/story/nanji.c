#include <ansi.h>

string give_gift();

inherit F_CLEAN_UP;

static mixed *story = ({
        "��Ŵ��ɣ��ϼ����̣������պá�",
        "�ϼ����̣��Ǻǣ���ã���á�",
        "��Ŵ��ɣ����������Ҹ�������",
        "�ϼ����̣����������������ִ�������֪����ϲ���Ⱦơ�",
        "��Ŵ��ɣ��������������ˣ����Ƕ�սʤ������ת�������",
        "�ϼ�������æ�ӹ���",
        "�ϼ����̿��˰��죬����ʲô�����գ��Ҳ�����ģ����������˷�Ҳ�Ĳ��˺��ԡ�",
        "�ϼ��������ְѵ�ҩ���˳�ȥ��",
        (: give_gift :),
        "�ϼ����̣�ʲô�����ҿ�ȥ���ң�",
        "��Ŵ��ɣ�����",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/fam/gift/con2", 1,
                           HIM "\n��ž����һ��һ���ɵ���������ǰ��\n\n" NOR);
        return "��Ŵ��ɼ�������������Ƕ�սʤ���ɷ������͵����ǵ�������ԡ�";
}
